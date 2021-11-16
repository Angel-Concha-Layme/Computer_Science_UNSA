#include <algorithm>
#include <functional>
#include <memory>
#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <math.h>
#include <ctime>
#include <ratio>
#include <fstream>
#include <numeric>

#define DIM 3


using point_t = std::vector< double >;
using indexArr = std::vector< size_t >;
using pointIndex = typename std::pair< std::vector< double >, size_t >;

class KDNode {
   public:
    using KDNodePtr = std::shared_ptr< KDNode >;
    size_t index;
    point_t x;
    KDNodePtr left;
    KDNodePtr right;

    // initializer
    KDNode();
    KDNode(const point_t &, const size_t &, const KDNodePtr &,
           const KDNodePtr &);
    KDNode(const pointIndex &, const KDNodePtr &, const KDNodePtr &);
    ~KDNode();

    // getter
    double coord(const size_t &);

    // conversions
    explicit operator bool();
    explicit operator point_t();
    explicit operator size_t();
    explicit operator pointIndex();
};


using KDNodePtr = std::shared_ptr< KDNode >;

KDNodePtr NewKDNodePtr();

// square euclidean distance
inline double dist2(const point_t &, const point_t &);
inline double dist2(const KDNodePtr &, const KDNodePtr &);

// euclidean distance
inline double dist(const point_t &, const point_t &);
inline double dist(const KDNodePtr &, const KDNodePtr &);

// Need for sorting
class comparer {
   public:
    size_t idx;
    explicit comparer(size_t idx_);
    inline bool compare_idx(
        const std::pair< std::vector< double >, size_t > &,  //
        const std::pair< std::vector< double >, size_t > &   //
    );
};

using pointIndexArr = typename std::vector< pointIndex >;

inline void sort_on_idx(const pointIndexArr::iterator &,  //
                        const pointIndexArr::iterator &,  //
                        size_t idx);

using pointVec = std::vector< point_t >;


class KDTree {
    KDNodePtr root;
    KDNodePtr leaf;

    KDNodePtr make_tree(const pointIndexArr::iterator &begin,  //
                        const pointIndexArr::iterator &end,    //
                        const size_t &length,                  //
                        const size_t &level                    //
    );

   public:
    KDTree() = default;
    explicit KDTree(pointVec point_array);

   private:
    KDNodePtr nearest_(           //
        const KDNodePtr &branch,  //
        const point_t &pt,        //
        const size_t &level,      //
        const KDNodePtr &best,    //
        const double &best_dist   //
    );

    // default caller
    KDNodePtr nearest_(const point_t &pt);

   public:
    point_t nearest_point(const point_t &pt);
    size_t nearest_index(const point_t &pt);
    pointIndex nearest_pointIndex(const point_t &pt);

   private:
    pointIndexArr neighborhood_(  //
        const KDNodePtr &branch,  //
        const point_t &pt,        //
        const double &rad,        //
        const size_t &level       //
    );

   public:
    pointIndexArr neighborhood(  //
        const point_t &pt,       //
        const double &rad);

    pointVec neighborhood_points(  //
        const point_t &pt,         //
        const double &rad);

    indexArr neighborhood_indices(  //
        const point_t &pt,          //
        const double &rad);
};



KDNode::KDNode() = default;

KDNode::KDNode(const point_t &pt, const size_t &idx_, const KDNodePtr &left_,
               const KDNodePtr &right_) {
    x = pt;
    index = idx_;
    left = left_;
    right = right_;
}

KDNode::KDNode(const pointIndex &pi, const KDNodePtr &left_,
               const KDNodePtr &right_) {
    x = pi.first;
    index = pi.second;
    left = left_;
    right = right_;
}

KDNode::~KDNode() = default;

double KDNode::coord(const size_t &idx) { return x.at(idx); }
KDNode::operator bool() { return (!x.empty()); }
KDNode::operator point_t() { return x; }
KDNode::operator size_t() { return index; }
KDNode::operator pointIndex() { return pointIndex(x, index); }

KDNodePtr NewKDNodePtr() {
    KDNodePtr mynode = std::make_shared< KDNode >();
    return mynode;
}

inline double dist2(const point_t &a, const point_t &b) {
    double distc = 0;
    for (size_t i = 0; i < a.size(); i++) {
        double di = a.at(i) - b.at(i);
        distc += di * di;
    }
    return distc;
}

inline double dist2(const KDNodePtr &a, const KDNodePtr &b) {
    return dist2(a->x, b->x);
}

inline double dist(const point_t &a, const point_t &b) {
    return std::sqrt(dist2(a, b));
}

inline double dist(const KDNodePtr &a, const KDNodePtr &b) {
    return std::sqrt(dist2(a, b));
}

comparer::comparer(size_t idx_) : idx{idx_} {};

inline bool comparer::compare_idx(const pointIndex &a, const pointIndex &b){
    return (a.first.at(idx) < b.first.at(idx));  //
}

inline void sort_on_idx(const pointIndexArr::iterator &begin, const pointIndexArr::iterator &end, size_t idx) {
    comparer comp(idx);
    comp.idx = idx;

    using std::placeholders::_1;
    using std::placeholders::_2;

    std::nth_element(begin, begin + std::distance(begin, end) / 2, end, std::bind(&comparer::compare_idx, comp, _1, _2));
}

using pointVec = std::vector< point_t >;

KDNodePtr KDTree::make_tree(const pointIndexArr::iterator &begin, const pointIndexArr::iterator &end, const size_t &length, const size_t &level) {
    if (begin == end) {
        return NewKDNodePtr();  // empty tree
    }

    size_t dim = begin->first.size();

    if (length > 1) {
        sort_on_idx(begin, end, level);
    }

    auto middle = begin + (length / 2);

    auto l_begin = begin;
    auto l_end = middle;
    auto r_begin = middle + 1;
    auto r_end = end;

    size_t l_len = length / 2;
    size_t r_len = length - l_len - 1;

    KDNodePtr left;
    if (l_len > 0 && dim > 0) {
        left = make_tree(l_begin, l_end, l_len, (level + 1) % dim);
    } else {
        left = leaf;
    }
    KDNodePtr right;
    if (r_len > 0 && dim > 0) {
        right = make_tree(r_begin, r_end, r_len, (level + 1) % dim);
    } else {
        right = leaf;
    }

    // KDNode result = KDNode();
    return std::make_shared< KDNode >(*middle, left, right);
}

KDTree::KDTree(pointVec point_array) {
    leaf = std::make_shared< KDNode >();
    // iterators
    pointIndexArr arr;
    for (size_t i = 0; i < point_array.size(); i++) {
        arr.push_back(pointIndex(point_array.at(i), i));
    }

    auto begin = arr.begin();
    auto end = arr.end();

    size_t length = arr.size();
    size_t level = 0;  // starting

    root = KDTree::make_tree(begin, end, length, level);
}

KDNodePtr KDTree::nearest_(const KDNodePtr &branch, const point_t &pt, const size_t &level, const KDNodePtr &best, const double &best_dist){
    double d, dx, dx2;

    if (!bool(*branch)) {
        return NewKDNodePtr();  // basically, null
    }

    point_t branch_pt(*branch);
    size_t dim = branch_pt.size();

    d = dist2(branch_pt, pt);
    dx = branch_pt.at(level) - pt.at(level);
    dx2 = dx * dx;

    KDNodePtr best_l = best;
    double best_dist_l = best_dist;

    if (d < best_dist) {
        best_dist_l = d;
        best_l = branch;
    }

    size_t next_lv = (level + 1) % dim;
    KDNodePtr section;
    KDNodePtr other;

    // select which branch makes sense to check
    if (dx > 0) {
        section = branch->left;
        other = branch->right;
    } else {
        section = branch->right;
        other = branch->left;
    }

    // keep nearest neighbor from further down the tree
    KDNodePtr further = nearest_(section, pt, next_lv, best_l, best_dist_l);
    if (!further->x.empty()) {
        double dl = dist2(further->x, pt);
        if (dl < best_dist_l) {
            best_dist_l = dl;
            best_l = further;
        }
    }
    // only check the other branch if it makes sense to do so
    if (dx2 < best_dist_l) {
        further = nearest_(other, pt, next_lv, best_l, best_dist_l);
        if (!further->x.empty()) {
            double dl = dist2(further->x, pt);
            if (dl < best_dist_l) {
                best_dist_l = dl;
                best_l = further;
            }
        }
    }

    return best_l;
};

// default caller
KDNodePtr KDTree::nearest_(const point_t &pt) {
    size_t level = 0;
    // KDNodePtr best = branch;
    double branch_dist = dist2(point_t(*root), pt);
    return nearest_(root,          // beginning of tree
                    pt,            // point we are querying
                    level,         // start from level 0
                    root,          // best is the root
                    branch_dist);  // best_dist = branch_dist
};

point_t KDTree::nearest_point(const point_t &pt) {
    return point_t(*nearest_(pt));
};
size_t KDTree::nearest_index(const point_t &pt) {
    return size_t(*nearest_(pt));
};

pointIndex KDTree::nearest_pointIndex(const point_t &pt) {
    KDNodePtr Nearest = nearest_(pt);
    return pointIndex(point_t(*Nearest), size_t(*Nearest));
}

pointIndexArr KDTree::neighborhood_(const KDNodePtr &branch,  const point_t &pt,  const double &rad, const size_t &level){
    double d, dx, dx2;

    if (!bool(*branch)) {
        // branch has no point, means it is a leaf,
        // no points to add
        return pointIndexArr();
    }

    size_t dim = pt.size();

    double r2 = rad * rad;

    d = dist2(point_t(*branch), pt);
    dx = point_t(*branch).at(level) - pt.at(level);
    dx2 = dx * dx;

    pointIndexArr nbh, nbh_s, nbh_o;
    if (d <= r2) {
        nbh.push_back(pointIndex(*branch));
    }

    //
    KDNodePtr section;
    KDNodePtr other;
    if (dx > 0) {
        section = branch->left;
        other = branch->right;
    } else {
        section = branch->right;
        other = branch->left;
    }

    nbh_s = neighborhood_(section, pt, rad, (level + 1) % dim);
    nbh.insert(nbh.end(), nbh_s.begin(), nbh_s.end());
    if (dx2 < r2) {
        nbh_o = neighborhood_(other, pt, rad, (level + 1) % dim);
        nbh.insert(nbh.end(), nbh_o.begin(), nbh_o.end());
    }

    return nbh;
};

pointIndexArr KDTree::neighborhood(const point_t &pt,const double &rad){
    size_t level = 0;
    return neighborhood_(root, pt, rad, level);
}

pointVec KDTree::neighborhood_points(const point_t &pt, const double &rad) {
    size_t level = 0;
    pointIndexArr nbh = neighborhood_(root, pt, rad, level);
    pointVec nbhp;
    nbhp.resize(nbh.size());
    std::transform(nbh.begin(), nbh.end(), nbhp.begin(), [](pointIndex x) { return x.first; });
    return nbhp;
}

indexArr KDTree::neighborhood_indices(const point_t &pt, const double &rad){
    size_t level = 0;
    pointIndexArr nbh = neighborhood_(root, pt, rad, level);
    indexArr nbhi;
    nbhi.resize(nbh.size());
    std::transform(nbh.begin(), nbh.end(), nbhi.begin(), [](pointIndex x) { return x.second; });
    return nbhi;
}


//FUNCIONES
double getNum();
std::vector<double> generateVector();
std::vector<std::vector<double>> getListofGeneratedVectors(int length);
double sumSqrdErr(std::vector<double>& p1, std::vector<double>& p2);

void error_test();
void construction_time();
void toy_test();





int main(){
    //error_test();
    //construction_time();
    toy_test();
	return 0;
}

double getNum(){
	return ((double)rand() / (RAND_MAX));
}

std::vector<double> generateVector(){
	std::vector<double> temp(DIM);
	for (size_t idx = 0; idx < DIM; idx++)
	{
		temp[idx] = getNum();
	}
	return temp;
}

std::vector<std::vector<double>> getListofGeneratedVectors(int length){
	std::vector<std::vector<double>> temp(length);
	for (size_t idx = 0; idx < length; idx++){
		temp[idx] = generateVector();
	}
	return temp;
}

double sumSqrdErr(std::vector<double>& p1, std::vector<double>& p2){
	std::vector<double>diff(DIM);
	std::vector<double>square(DIM);
	std::transform(p1.begin(), p1.end(), p2.begin(), diff.begin(), std::minus<double>());
	std::transform(diff.begin(), diff.end(), diff.begin(), square.begin(), std::multiplies<double>());
	return std::accumulate(square.begin(), square.end(), 0.0);
}


void error_test(){
	// seed
	srand(5);

	const std::vector<int> dataPointSizes = { 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000 };
	constexpr int nIter = 50;

	std::cout << "Total number of iterations ran: " << nIter << std::endl;

	for (auto& sizes : dataPointSizes){
		std::vector< std::vector<double> > points(sizes, std::vector<double>(DIM)), pointToRetrieve(sizes, std::vector<double>(DIM));
		long long kdTreeRetTotalTime = 0.0;
		long long bruteForceRetTotalTime = 0.0;

		int correct = 0;
		for (int i = 0; i < nIter; i++){
			// generate test points to build a tree
			points = getListofGeneratedVectors(sizes);

			// genereate KD Tree
			KDTree tree(points);

			// generate retrieve test data points
			pointToRetrieve = getListofGeneratedVectors(sizes);

			for (auto& vals : pointToRetrieve){
				double minSumSqdErr = std::numeric_limits<double>::max();
				std::vector<double> groundTruthVec(DIM);
				for (auto& gtvals : points) { // loop through all the points that built KDTRee
					double sumSqdErr = sumSqrdErr(gtvals, vals);
					if (sumSqdErr < minSumSqdErr){
						minSumSqdErr = sumSqdErr;
						groundTruthVec = gtvals;
					}
				}
				std::vector <double> checkVec(DIM);
				checkVec = tree.nearest_point(vals);
				if (std::equal(groundTruthVec.begin(), groundTruthVec.end(), checkVec.begin())){
					correct += 1;
				}		
			}
		}
		std::cout << "\n\nAccuracy (tested with " << sizes << " datasets per iter) = " << ((correct * 100.0) / (sizes*nIter)) << " %.  Avg. Total Number Correct: " << (int)(correct / nIter) << " / " << sizes;
	}
}


void construction_time(){
    // seed
	srand(5);

    size_t npoints = 400000;
    std::cout << "constructing KDTree with " << npoints << " points." << std::endl;

    std::vector<point_t> points = getListofGeneratedVectors(npoints);

    auto start = std::chrono::high_resolution_clock::now();
    KDTree tree(points);
    auto stop = std::chrono::high_resolution_clock::now();
    auto timespan = std::chrono::duration<double>(stop - start);
    std::cout << "it took " << timespan.count() << " seconds.";
}


void toy_test(){
    pointVec points;
    point_t pt;

    pt = {0.0, 0.0};
    points.push_back(pt);
    pt = {1.0, 0.0};
    points.push_back(pt);
    pt = {0.0, 1.0};
    points.push_back(pt);
    pt = {1.0, 1.0};
    points.push_back(pt);
    pt = {0.5, 0.5};
    points.push_back(pt);

    KDTree tree(points);

    std::cout << "nearest test\n";
    pt = {0.8, 0.2};
    auto res = tree.nearest_point(pt);
    for (double b : res) {
        std::cout << b << " ";
    }
    std::cout << '\n';

    /*
    std::cout << "going down the tree\n";
    for (auto b : point_t(*tree)) {
        std::cout << b << " ";
    }
    std::cout << '\n';
    for (auto b : point_t(*tree->left)) {
        std::cout << b << " ";
    }
    std::cout << '\n';
    for (auto b : point_t(*tree->right)) {
        std::cout << b << " ";
    }
    std::cout << '\n';
    for (auto b : point_t(*tree->left->left)) {
        std::cout << b << " ";
    }
    std::cout << '\n';
    for (auto b : point_t(*tree->right->left)) {
        std::cout << b << " ";
    }
    std::cout << '\n';
    std::cout << "printing nbh\n";
    pt = {.0, .5};
    */
    auto res2 = tree.neighborhood_points(pt, .55);

    for (point_t a : res2) {
        for (double b : a) {
            std::cout << b << " ";
        }
        std::cout << '\n';
    }
}