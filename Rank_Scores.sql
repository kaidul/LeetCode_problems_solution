select Score,
(select count(distinct Score) from Scores where Score >= S.Score) as Rank
from Scores S
order by Score desc;