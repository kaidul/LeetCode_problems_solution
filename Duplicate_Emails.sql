# Write your MySQL query statement below

# TLE - don't know why
#select Email from Person where Id in (select min(Id) from Person group by Email having count(Id) > 1);

select Email
from Person
where Id in (select P.Id from (select min(ID) as ID from Person group by Email having count(ID) > 1) as P)

# join
select distinct P1.Email from Person P1, Person P2 where P1.Email = P2.Email and P1.Id <> P2.Id;

#simpler query
select Email
from Person
group by Email
having count(*) > 1;
