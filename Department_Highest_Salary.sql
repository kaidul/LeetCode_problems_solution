select d.Name as Department,
e.name as Employee,
Salary
from Employee e
join Department d
on e.DepartmentId = d.Id
where (Salary, DepartmentId) in
(select max(Salary), DepartmentId from Employee group by DepartmentId);

# another solution
select d.Name as Department,
e.name as Employee,
Salary
from Employee e join Department d
on e.DepartmentId = d.Id
where Salary = (select max(Salary) from Employee e2 where e2.DepartmentId = d.Id);