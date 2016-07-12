select distinct L1.Num
as ConsecutiveNums
from Logs L1, Logs L2, Logs L3
where L1.Id = L2.Id - 1 and L2.Id = L3.Id - 1
and L1.Num = L2.Num and L2.Num = L3.Num;

# 2
select distinct L1.Num
as ConsecutiveNums
from Logs L1
inner join Logs L2
on L1.Id = L2.Id - 1

inner join Logs L3
on L2.Id = L3.Id - 1

where L1.Num = L2.Num and L2.Num = L3.Num;