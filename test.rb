require "numo/narray"
s_score=Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
e_score=Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]
print("笑介くんのクラス20人のテストの点数は、理科が\n")
for i in 0..19
	print(" ",s_score[i])
end
print("\n英語が\n")
for i in 0..19
	print(" ",e_score[i])
end
print("\nでした\n")

print("理科の平均は",s_score.mean)
print("\n英語の平均は",e_score.mean)
print("\n理科の標準偏差は",s_score.stddev)
print("\n英語の標準偏差は",e_score.stddev)
print("\n理科の合計点は",s_score.sum)
print("\n英語の合計点は",e_score.sum)
print("\n各学生の偏差値は\n")

for i in 0..19
	print("学生 ",i)
	print(" 理科 ",10*(s_score[i]-s_score.mean)/s_score.stddev+50)
	print(" 英語 ",10*(e_score[i]-e_score.mean)/e_score.stddev+50)
	print("\n")
end
print("理科の得点順は\n",s_score.sort)
