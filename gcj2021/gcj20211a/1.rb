##### AC


gets.to_i.times do |case_id|
  print "Case ##{case_id + 1}: "
  n = gets.to_i
  x = gets.split.map &:to_i

  ans = 0
  old = x[0]
  x[1..-1].each do |y|
    l, r = y, y + 1
    while r <= old + 1 do
      l *= 10
      r *= 10
      ans += 1
    end
    old = [l, old + 1].max
  end

  p ans
end
