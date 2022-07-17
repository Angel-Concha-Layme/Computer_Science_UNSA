create DATABASE worldcare;
use worldcare;

create Table usuarios(
    ID_usuario int not null auto_increment,
    nombre varchar(50) not null,
    apellido varchar(50) not null,
    email varchar(50) not null,
    contrasena varchar(50) not null,
    primary key(ID_usuario)
);

create table publicaciones(
    ID_publicacion int not null auto_increment,
    ID_usuario int not null,
    titulo varchar(50) not null,
    descripcion varchar(500) not null,
    primary key(ID_publicacion),
    foreign key(ID_usuario) references usuarios(ID_usuario)
);


create table categorias(
    ID_categoria int not null auto_increment,
    nombre varchar(50) not null,
    primary key(ID_categoria)
);

create table interacciones(
    ID_interaccion int not null auto_increment,
    ID_usuario int not null,
    ID_publicacion int not null,
    primary key(ID_interaccion),
    foreign key(ID_usuario) references usuarios(ID_usuario),
    foreign key(ID_publicacion) references publicaciones(ID_publicacion)
);


create table categorias_publicaciones(
    ID_categoria int not null,
    ID_publicacion int not null,
    primary key(ID_categoria, ID_publicacion),
    foreign key(ID_categoria) references categorias(ID_categoria),
    foreign key(ID_publicacion) references publicaciones(ID_publicacion)
);

create table comentarios(
    ID_comentario int not null auto_increment,
    ID_usuario int not null,
    ID_publicacion int not null,
    comentario varchar(500) not null,
    primary key(ID_comentario),
    foreign key(ID_usuario) references usuarios(ID_usuario),
    foreign key(ID_publicacion) references publicaciones(ID_publicacion)
);
