# Write your MySQL query statement below
SELECT e1.name
FROM employee AS e1
JOIN (
    SELECT e2.managerId
    FROM employee as e2
    GROUP BY e2.managerId
    HAVING COUNT(*) >= 5
) AS sub
ON e1.id = sub.managerId;
