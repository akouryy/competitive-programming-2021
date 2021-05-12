require 'set'

H, W = gets.split.map &:to_i
S = *$<

dp = {}
q = []
begin
  a = Set.new
  S.each_with_index do |l, i|
    l.bytes.each_with_index do |c, j|
      a << [i, j] if c == 35
    end
  end
  4.times do |i|
    1.upto(2) do |j|
      k = [a, [i, j]]
      dp[k] = []
      q << k
    end
  end
end

DIRS = [[-1,0],[0,1],[1,0],[0,-1]].freeze

# p dp, q

until q.empty?
  a, (i, j) = b = q.shift
  # p b
  DIRS.each do |di,dj|
    ii = i + di
    jj = j + dj
    g = [ii, jj]
    if 0 <= ii && ii < 4 && 0 <= jj && jj < 4 && a.member?(g)
      aa = a - [g]
      aag = [aa, g]
      unless dp[aag]
        dp[aag] = dp[b] + [[ii+1, jj+1]]
        q << aag
      end
      break if aa.empty?
    end
  end
end

_, ans = dp.find{|(a,_),| a.empty? }
puts ans.size, ans.map{_1 * ?\s}
