require "digest"

LONG_TO_SHORT = {}

def encode(long_url)
  short_url = Digest::SHA1.hexdigest(long_url)
  LONG_TO_SHORT[short_url] = long_url
  short_url
end

def decode(short_url)
  LONG_TO_SHORT.fetch(short_url)
end

