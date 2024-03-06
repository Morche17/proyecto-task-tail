#!/usr/bin/env ruby
require 'yaml'

# Método para leer los datos del archivo YAML
def leer_datos(archivo)
  if File.exist?(archivo)
    File.read(archivo)
  else
    "{}\n"
  end
end

# Método para actualizar los datos con las nuevas llaves y valores
def actualizar_datos(datos, key, value)
  datos[key] = value
  datos
end

# Método para escribir los datos actualizados en el archivo YAML
def escribir_datos(archivo, datos)
  File.write(archivo, YAML.dump(datos))
end

# Obtener la fecha actual para usarla como parte del nombre del archivo
fecha_actual = Time.now.strftime("%Y-%m-%d")
archivo = "misDatos/#{fecha_actual}.yml"

# Llave proporcionada como primer argumento
nueva_llave = ARGV[0]

# Valor proporcionado como el resto de los argumentos
nuevo_valor = ARGV.drop(1).join(" ")

# Leer los datos del archivo YAML
contenido = leer_datos(archivo)
datos = YAML.load(contenido)

# Actualizar los datos con la nueva llave y valor
datos = actualizar_datos(datos, nueva_llave, nuevo_valor)

# Escribir los datos actualizados en el archivo YAML
escribir_datos(archivo, datos)

puts "Datos actualizados en #{archivo}:"
puts YAML.dump(datos)

