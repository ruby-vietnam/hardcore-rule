def SJF(jobs, index)
  target_job = jobs[index]
  
  jobs.each_with_index.reduce(0) do |total, (job, job_index)|
    if job < target_job || (job == target_job && job_index <= index)
      total + job
    else
      total
    end
  end
end
