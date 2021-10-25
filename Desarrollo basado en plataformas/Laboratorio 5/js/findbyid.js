
$(document).ready(function(){
	$( "#buton" ).on('click', function(e) {
	    e.preventDefault();
	    $.ajax({
	        url: "http://localhost:8080/CategoryRestService/FindById/".concat($('.to_search').val())
	    }).then(function(data) {
	    	//$('#url').atrr('href', url);

	       $('.id').empty().append(data.id);
	       $('.c-date').empty().append(data.whenCreated);
	       $('.a-date').empty().append(data.whenLastUpdated);
	       $('.name').empty().append(data.name);
	       $('.description').empty().append(data.description);

	       $('#url').atrr('href', "http://localhost:8080/CategoryRestService/FindById/".concat($('.to_search').val()));
	    });
	});
});