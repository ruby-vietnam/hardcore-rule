fn sjf(jobs: &[usize], index: usize) -> usize {
  //your code here
  let mut sorted_jobs = jobs.iter().enumerate().collect::<Vec<_>>();
  sorted_jobs.sort_by_key(|&(_, cost)| *cost);
  let mut sum_cost = 0usize;
  for (idx, cost) in sorted_jobs {
      sum_cost += *cost;
      if idx == index {
          break;
      }
  }

  sum_cost
}
