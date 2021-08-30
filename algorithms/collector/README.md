# Algorithm Collector

## Basic flow

 1. Query open pull requests
 2. Query mapping between github account and slack account from: https://raw.githubusercontent.com/ruby-vietnam/hardcore-rule/master/algorithms/PARTICIPANTS.md
 3. Query problem's scrores of current week from:
	- List of problems in latest comment of issue: https://github.com/ruby-vietnam/hardcore-rule/issues/1408
	- Mapping between level and score in first comment of issue: https://github.com/ruby-vietnam/hardcore-rule/issues/1408
 4. With (1), (2) and (3), algorithm collector combines and calculate earning score of PRs. PRs are merged.
 5. Add new reply in latest comment of https://github.com/ruby-vietnam/hardcore-rule/issues/1408

## Configurations

| Configuration | Default           | Description |
| ------------- |:-----------------:| ----- |
| OWNER         | <empty> | Required .Github owner name |
| REPO          | <empty> | Required. Github repository name |
| ACCESS_TOKEN  | <empty> | Github developmer ACCESS TOKEN to give tool permission to access Github API |
| PR_PREFIX     | <empty> | Pull request prefix name condition in querying to calculate score |
| REAL_MODE | false   | Allow to run real mode by merging, comment score and summary comment |
