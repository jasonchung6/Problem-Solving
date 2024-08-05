-- 코드를 입력하세요
SELECT a.car_id, round(avg(a.day),1) as AVERAGE_DURATION
from (select car_id, datediff(end_date,start_date)+1 as day from CAR_RENTAL_COMPANY_RENTAL_HISTORY) as a
group by a.car_id
having AVERAGE_DURATION>=7.0
order by 2 desc, 1 desc