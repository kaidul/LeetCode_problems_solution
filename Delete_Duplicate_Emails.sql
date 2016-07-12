# Write your MySQL query statement below
# select * from Person where Id in(select min(Id) from Person GROUP BY(Email)); // TLE

DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id

# faster solution
delete from Person where Id not in(select P.ID from (select min(Id) as ID from Person group by Email) as P);