package actions

import (
	"os"
	"reflect"
	"testing"
)

func clearAppEnvs() {
	os.Unsetenv(envOwner)
	os.Unsetenv(envRepo)
	os.Unsetenv(envAccessToken)
	os.Unsetenv(envPRPrefix)
	os.Unsetenv(envDisableMerge)
}
func setAppEnvs(owner, repo, accessToken, prPrefix, disableMerge *string) {
	if owner != nil {
		os.Setenv(envOwner, *owner)
	}
	if repo != nil {
		os.Setenv(envRepo, *repo)
	}
	if accessToken != nil {
		os.Setenv(envAccessToken, *accessToken)
	}
	if prPrefix != nil {
		os.Setenv(envPRPrefix, *prPrefix)
	}
	if disableMerge != nil {
		os.Setenv(envDisableMerge, *disableMerge)
	}
}

func TestGetParams(t *testing.T) {
	tests := []struct {
		name            string
		envOwner        *string
		envRepo         *string
		envAccessToken  *string
		envPRPrefix     *string
		envDisableMerge *string
		want            params
		wantErr         bool
	}{
		{
			name:           "missing owner",
			envOwner:       nil,
			envRepo:        ptrStr("hardcore-rule"),
			envAccessToken: ptrStr("FAKE_TOKEN"),
			envPRPrefix:    ptrStr("TEST_"),
			want:           params{},
			wantErr:        true,
		},
		{
			name:           "missing repo",
			envOwner:       ptrStr("ruby-vietnam"),
			envRepo:        nil,
			envAccessToken: ptrStr("FAKE_TOKEN"),
			envPRPrefix:    ptrStr("TEST_"),
			want:           params{},
			wantErr:        true,
		},
		{
			name:           "missing access token",
			envOwner:       ptrStr("ruby-vietnam"),
			envRepo:        ptrStr("hardcore-rule"),
			envPRPrefix:    ptrStr("TEST_"),
			envAccessToken: nil,
			want:           params{},
			wantErr:        true,
		},
		{
			name:           "missing disable merge",
			envOwner:       ptrStr("ruby-vietnam"),
			envRepo:        ptrStr("hardcore-rule"),
			envPRPrefix:    ptrStr("TEST_"),
			envAccessToken: ptrStr("FAKE_TOKEN"),
			want: params{
				owner:        "ruby-vietnam",
				repo:         "hardcore-rule",
				accessToken:  "FAKE_TOKEN",
				prPrefix:     "TEST_",
				disableMerge: false,
			},
			wantErr: false,
		},
		{
			name:            "full envs",
			envOwner:        ptrStr("ruby-vietnam"),
			envRepo:         ptrStr("hardcore-rule"),
			envAccessToken:  ptrStr("FAKE_TOKEN"),
			envPRPrefix:     ptrStr("TEST_"),
			envDisableMerge: ptrStr("true"),
			want: params{
				owner:        "ruby-vietnam",
				repo:         "hardcore-rule",
				accessToken:  "FAKE_TOKEN",
				prPrefix:     "TEST_",
				disableMerge: true,
			},
			wantErr: false,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			clearAppEnvs()
			setAppEnvs(tt.envOwner, tt.envRepo, tt.envAccessToken, tt.envPRPrefix, tt.envDisableMerge)

			got, err := GetParams()
			if (err != nil) != tt.wantErr {
				t.Errorf("getParams() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("getParams() = %v, want %v", got, tt.want)
			}
		})
	}
}
