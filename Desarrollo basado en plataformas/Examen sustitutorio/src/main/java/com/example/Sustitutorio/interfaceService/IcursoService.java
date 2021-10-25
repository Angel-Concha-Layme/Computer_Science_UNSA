package com.example.Sustitutorio.interfaceService;
import java.util.List;
import java.util.Optional;

import com.example.Sustitutorio.modelo.Curso;
public interface IcursoService {
	public List<Curso>listar();
	public Optional<Curso> ListarID(int id);
	public int save(Curso c);
	public void delete(int id);
}
