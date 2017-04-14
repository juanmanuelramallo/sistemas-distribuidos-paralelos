if ARGV.count < 5
  puts "Missing arguments"
  puts "\t * N cantidad de elementos del vector"
  puts "\t * MAX_NUM numero maximo de cada elemento del vector"
  puts "\t * X elemento a buscar ocurrencias"
  puts "\t * T cantidad de threads"
  puts "\t * I imprime?"
  return
end

N = ARGV[0].to_i
MAX_NUM = ARGV[1].to_i
X = ARGV[2].to_i
T = ARGV[3].to_i
imprimir = ARGV[4].to_i

puts "\t * #{N} cantidad de elementos del vector"
puts "\t * #{MAX_NUM} numero maximo de cada elemento del vector"
puts "\t * #{X} elemento a buscar ocurrencias"
puts "\t * #{T} cantidad de threads"
puts "\t * #{imprimir} imprime?"

if N < T
  puts "La cantidad de elementos no puede ser menor a la cantidad de threads"
  return
end

@ocurrencias = 0
@ocurrencias_vector = []
@vector = []

(1..N).each do
  @vector.push(rand(MAX_NUM))
end

puts "#{@vector.map{|v| v}}" if imprimir

def contar_ocurrencias(index)
  last_position = index*(N/T) + ((N/T)-1)
  first_position = index*(N/T)
  for i in first_position..last_position
    if (@vector[i] == X)
      @ocurrencias_vector[index] = @ocurrencias_vector[index] + 1
    end
  end

  if index == T-1
    @ocurrencias_vector.each do |conteo_parcial|
      @ocurrencias = @ocurrencias + conteo_parcial
    end
  end
end

threads = []
START = Time.now
(0..T-1).each do |thread_number|
  @ocurrencias_vector[thread_number] = 0
  threads << Thread.new { contar_ocurrencias(thread_number) }
end

threads.each do |thread|
  thread.join
end

puts "...Tiempo obtenido: #{Time.now - START}"
puts "Ocurrencias obtenidas -> #{@ocurrencias}"

threads.each do |thread|
  thread.exit
end

#TODO : Not working as expected.. debug it
