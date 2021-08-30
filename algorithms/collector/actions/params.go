package actions

import (
	"errors"
	"os"
	"strconv"
)

const (
	envOwner       = "OWNER"
	envRepo        = "REPO"
	envAccessToken = "ACCESS_TOKEN"
	envPRPrefix    = "PR_PREFIX"
	envRealMode    = "REAL_MODE"
)

type params struct {
	owner       string
	repo        string
	accessToken string
	prPrefix    string
	realMode    bool
}

func GetParams() (params, error) {
	if os.Getenv(envOwner) == "" {
		return params{}, errors.New("missing OWNER parameter")
	}

	if os.Getenv(envRepo) == "" {
		return params{}, errors.New("missing REPO parameter")
	}

	if os.Getenv(envAccessToken) == "" {
		return params{}, errors.New("missing ACCESS_TOKEN parameter")
	}

	realMode, _ := strconv.ParseBool(os.Getenv(envRealMode))

	return params{
		owner:       os.Getenv(envOwner),
		repo:        os.Getenv(envRepo),
		accessToken: os.Getenv(envAccessToken),
		prPrefix:    os.Getenv(envPRPrefix),
		realMode:    realMode,
	}, nil
}

func (p params) GetPRPrefix() string {
	return p.prPrefix
}

/* IsRealMode supports:
- Add a comment each PR
- Merge PR
- Delete branch
- Comment a score summary issue of algorithm
*/
func (p params) IsRealMode() bool {
	return p.realMode
}
