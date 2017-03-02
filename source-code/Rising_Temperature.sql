# Write your MySQL query statement below
Select w1.Id from Weather w1
join Weather w2
where w1.Temperature > w2.Temperature and datediff(w1.Date, w2.Date) = 1;

# using subdate()
SELECT 
    t1.Id
From 
    Weather t1, Weather t2
WHERE 
    t1.Temperature > t2.Temperature
AND
    subdate(t1.Date, 1) = t2.Date