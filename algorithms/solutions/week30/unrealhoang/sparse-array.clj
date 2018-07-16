; TODO: Use trie
; Complete the matchingStrings function below.
(defn matchingStrings [strings queries]
    (let [count-map (->> strings
                         (group-by identity)
                         (map (fn [[key val]] [key (count val)]))
                         (into {}))]
        (->> queries
             (map count-map)
             (map (fnil identity 0))))
)
