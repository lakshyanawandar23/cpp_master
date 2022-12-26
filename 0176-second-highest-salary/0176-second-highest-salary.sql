# Write your MySQL query statement belows
select ifnull(null,(select distinct salary from employee order by salary desc limit 1,1)) as SecondHighestSalary;