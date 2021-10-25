var tabla = [
	{nombre: "elemento1", descripcion: "Descripcion1"},
	{nombre: "elemento2", descripcion: "Descripcion2"},
	{nombre: "elemento3", descripcion: "Descripcion3"}
];

window.onload = cargarEventos;


function cargarEventos()
{
	document.getElementById("mostrar-tabla").addEventListener("click",mostrarTabla);
	

}


function mostrarTabla()
{
	alert("Hello");
	 var contenidoTabla = document.getElementById("elementos");
	 var tablaLlena = "";
	 
	 for (var k = 0; k < tabla.length; k++)
	 {
		 tablaLlena += "<tr> <td>"+ tabla[k].nombre +"</td> <td>"+ tabla[k].descripcion +"</td> </tr>";
	 }
	 
	 contenidoTabla.innerHTML = tablaLlena;
}