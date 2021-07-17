OWNER=ruby-vietnam
REPO=hardcore-rule
TEST_PR_PREFIX=TEST

run:
	OWNER=$(OWNER) \
	REPO=$(REPO) \
	go run main.go

test:
	PR_PREFIX_TEST=$(TEST_PR_PREFIX) \
	DISABLE_MERGE=true \
	OWNER=$(OWNER) \
	REPO=$(REPO) \
	go run main.go
