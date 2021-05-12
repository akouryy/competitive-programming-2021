(N,L,T,X),*AB=$<.map{_1.split.map &:to_i}
ans = 0
hot = 0
if AB.any?{|a,b| L <= b && T < a }
  puts :forever
  exit
end

AB.each do |a,b|
  if b < L
    ans += a
    hot = 0
  else
    if hot + a > T
      ans += (T - hot) + X
      hot = 0
      redo
    elsif hot + a == T
      ans += a + X
      hot = 0
    else
      ans += a
      hot += a
    end
  end
  # p [a,b,ans,hot]
end
p ans
