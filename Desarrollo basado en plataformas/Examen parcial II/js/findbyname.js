
$(document).ready(function(){
	$( "#buton" ).on('click', function(e) {
	    e.preventDefault();
	    $.ajax({
	        url: "http://localhost:8080/CategoryRestService/FindByName/".concat($('.to_search').val())
	    }).then(function(data) {
	       $('.id').empty().append(data.id);
	       $('.c-date').empty().append(data.whenCreated);
	       $('.a-date').empty().append(data.whenLastUpdated);
	       $('.name').empty().append(data.name);
	       $('.description').empty().append(data.description);
	    });
	});
});