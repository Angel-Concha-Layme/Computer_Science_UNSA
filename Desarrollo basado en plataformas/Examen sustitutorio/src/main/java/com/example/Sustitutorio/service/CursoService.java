package com.example.Sustitutorio.service;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import com.example.Sustitutorio.interfaceService.IcursoService;
import com.example.Sustitutorio.interfaces.ICurso;
import com.example.Sustitutorio.modelo.Curso;
public class CursoService implements IcursoService {

	@Autowired
	private ICurso data;
	 
	@Override
	public List<Curso> listar() {
		
		return (List<Curso>)data.findAll();
	}

	@Override
	public Optional<Curso> ListarID(int id) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int save(Curso c) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public void delete(int id) {
		// TODO Auto-generated method stub
		
	}
	
	

}
