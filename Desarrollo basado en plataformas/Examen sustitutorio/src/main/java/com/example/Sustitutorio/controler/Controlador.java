package com.example.Sustitutorio.controler;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.example.Sustitutorio.interfaceService.IcursoService;
import com.example.Sustitutorio.modelo.Curso;

import antlr.collections.List;

@Controller
@RequestMapping
public class Controlador {
	@Autowired
	private IcursoService service;
	
	@GetMapping("/listar")
	public String listar(Model model) {
		List<Curso>cursos= service.listar();
		model.addAttribute("cursos", cursos);
		return "intex";
	}
} 
