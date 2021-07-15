package actions

import (
	"errors"
	"os"
	"strconv"
)

const (
	envOwner        = "OWNER"
	envRepo         = "REPO"
	envAccessToken  = "ACCESS_TOKEN"
	envPRPrefix     = "PR_PREFIX"
	envDisableMerge = "DISABLE_MERGE"
)

type params struct {
	owner        string
	repo         string
	accessToken  string
	prPrefix     string
	disableMerge bool
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

	disableMerge, _ := strconv.ParseBool(os.Getenv(envDisableMerge))

	return params{
		owner:        os.Getenv(envOwner),
		repo:         os.Getenv(envRepo),
		accessToken:  os.Getenv(envAccessToken),
		prPrefix:     os.Getenv(envPRPrefix),
		disableMerge: disableMerge,
	}, nil
}

func (p params) GetPRPrefix() string {
	return p.prPrefix
}

func (p params) IsDisableMerge() bool {
	return p.disableMerge
}
