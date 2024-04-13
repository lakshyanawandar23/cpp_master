# Write your MySQL query statement below
Select  record.name from  (Select  A.name ,Count(A.id) as Cnt from Employee as A , Employee as B 
 where A.id=B.managerId 
        group by A.name,A.id) as record where Cnt>=5;