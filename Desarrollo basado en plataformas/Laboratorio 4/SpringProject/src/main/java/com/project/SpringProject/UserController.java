package com.project.SpringProject;

import java.util.ArrayList;
import java.util.Iterator;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@CrossOrigin(origins = "*")
@RequestMapping("/user")
public class UserController 
{
	public ArrayList<Elemento> lista = new ArrayList<Elemento>();
	Elemento elem;
	
		
	@GetMapping
	public String getUser()
	{
		
		String todo="[ ";
		String aux;
		Iterator<Elemento> it = lista.iterator();
		
		while(it.hasNext())
		{
			elem = it.next();
			aux = "{ nombre: "+ elem.getNombre()+ "  descripcion: "+elem.getDescripcion()+ " }";
			todo += aux; 
		}
		todo += " ]";
		 
		return todo;
	}
	
	@PostMapping
	public void createUser( String nombre, String descripcion)
	{
		elem.setNombre(nombre);
		elem.setDescripcion(descripcion);
		lista.add(elem);
	}
	
	
	@DeleteMapping
	public void deleteUser( int id)
	{
		lista.remove(id);		
	}
	
	
	
}
