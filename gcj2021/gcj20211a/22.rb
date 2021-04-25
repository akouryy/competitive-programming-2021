require 'prime'
p 2
p 95
Prime.each(499).map {|q|
  puts "#{q} #{10**13}"
}
p 95
Prime.each(499).map {|q|
  puts "#{q} #{q == 499 ? 10**15-94 : 1}"
}
