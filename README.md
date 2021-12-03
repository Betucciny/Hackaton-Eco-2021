# Hackaton-Eco-2021

# ECO

## ¿Qué hace ECO?

Este proyecto es un prototipo de aplicación para una plataforma de recoleccion de materiales reciclables
Cuenta con una pantalla de inicio de sesión y un sistema de registro de cuentas conectado a una tabla de una base de datos
El inicio de sesion depende de el tipo de usuario y estos redireccionará a la persona a la ventana correspondiente, ya sea de vendedor o de recolector.
Con el inicio de sesión se guarda el id de la base de datos donde se encuentra el usuario por si se necesita acceder más adelante.

### Vendedor

En la pantalla de vendedor se podrán observar varias secciones, en una caja de texto se le permite ingresar el código de barras de un producto para saber que tipo de residuo genera, todo esto a través de una consulta de otra tabla de la base de datos.
Con el botón de recolección se podrá solicitar el proceso de recolección de un tipo de residuo, especificando el tipo, cantidad y direccion a recoger, lo  que generará una nueva fila de la base de datos, que se pdrá acceder desde la sesión del recolecotor.


### Recolector

En la pantalla de recolector se podrá observar la pantalla de principal, a partir de la cuál se puede acceder a la pantalla de estatus, la cual se conecta a la base de datos de pedidos en la que obtendrá la direccion y un croquis, y en el caso en que haya varios pedidos, se podrá iterar con la pulsación de un botón

## Proyecciones

Para avanzar el proyecto se buscará adaptar una conexión de base de datos por un framework, lo que permitirá que se establezca la conexión de manera inalambrica, además de obtener acceso a una base de datos con los productos a través de gs1. Por otro lado, se buscará incluir un escaner de códigos de barras a través de la camara del dispositivo.

## Implementación

Para la implementación en otro dispositivo, se deberá modificar las diferentes partes del código que redireccionan a imagenes o a la base de datos, ya que estas se encontrarán en otra ubicación.
