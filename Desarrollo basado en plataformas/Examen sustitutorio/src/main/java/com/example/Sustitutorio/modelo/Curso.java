package com.example.Sustitutorio.modelo;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Table;
import javax.persistence.Id;


@Entity
@Table(name="curso")

public class Curso {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private int id;
	private int creditos;
	private String nombre;
	
	public Curso() {
		
	}

	public Curso(int id, int creditos, String nombre) {
		super();
		this.id = id;
		this.creditos = creditos;
		this.nombre = nombre;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getCreditos() {
		return creditos;
	}

	public void setCreditos(int creditos) {
		this.creditos = creditos;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	
	
}
