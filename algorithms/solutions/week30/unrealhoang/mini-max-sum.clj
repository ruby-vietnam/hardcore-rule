; Complete the miniMaxSum function below.
(defn miniMaxSum [arr]
    (let [sum (apply + arr)
          min (apply min arr)
          max (apply max arr)
          min-sum (- sum max)
          max-sum (- sum min)]
        (print min-sum max-sum))
)
