# Write your MySQL query statement below
select Name
as Customers
from Customers
where Id not in (select CustomerId from Orders);

#faster
select Name 
as Customers
from Customers
where (select count(*)
        from Orders
        where Orders.CustomerId = Customers.Id) = 0