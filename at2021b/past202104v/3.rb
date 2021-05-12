_,*A,(_,Q),B=$<.map{_1.split.map &:to_i}; p A.count{|_,*a| Q<=(a&B).size }
