$(document).ready(function(){
	
	$("#buton").click(function(e){
		e.preventDefault();

		var serviceURL = "http://localhost:8080/CategoryRestService/Add";
		var contenido = {"name":$('#name').val(),
						"description":$('#description').val()};
		
		$.ajax({
			url: serviceURL,
			type: 'put',
			headers: {"X-HTTP-Method-Override": "PUT"},
			contentType : "application/json",
			data: JSON.stringify(contenido),
			dataType : 'json',
			
			success: function(){
				console.log("Category saved correctly!");
			},
			error: function(){
				console.log("Error saving category! :(");
			}
		}).then(function(data){
			console.log(data);
		});
	});

});
