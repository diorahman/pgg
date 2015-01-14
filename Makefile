test: 
		@NODE_ENV=test ./node_modules/.bin/mocha \
			--require should \
			test/*.js

build:
		node-gyp rebuild

.PHONY: test build
