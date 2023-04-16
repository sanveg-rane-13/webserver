PROJECT_NAME=webserver
PROJECT_VERSION=1.0

DOCKER_DEPS_REPO?=${PROJECT_NAME}/
DOCKER_DEPS_IMAGE?=${PROJECT_NAME}_build
DOCKER_DEPS_FILE?=Dockerfile

.SILENT: build-image
build-image: ## Build the deps image.
	docker build --no-cache=true -t ${DOCKER_DEPS_IMAGE}:${PROJECT_VERSION} \
		-f ./${DOCKER_DEPS_FILE} .
	@echo
	@echo "Build finished. Docker image name: \"${DOCKER_DEPS_IMAGE}:${PROJECT_VERSION}\"."

LOCAL_SOURCE_PATH?=${CURDIR}
DOCKER_SOURCE_PATH?=/${PROJECT_NAME}
DOCKER_BUILD_DIR?=build

DOCKER_BASIC_RUN_PARAMS?=-it --init --rm \
					  --memory-swap=-1 \
					  --ulimit core=-1 \
					  --name="${DOCKER_DEPS_IMAGE}" \
					  --workdir=${DOCKER_SOURCE_PATH} \
					  --mount type=bind,source=${LOCAL_SOURCE_PATH},target=${DOCKER_SOURCE_PATH} \
					  ${DOCKER_DEPS_IMAGE}:${PROJECT_VERSION}

DOCKER_SHELL?=bash
DOCKER_CMAKE_FLAGS?=

.SILENT: gen-cmake
gen-cmake: ## Generate cmake files, use with build.
	docker run ${DOCKER_BASIC_RUN_PARAMS} \
		${DOCKER_SHELL} -c \
			"mkdir -p ${DOCKER_SOURCE_PATH}/${DOCKER_BUILD_DIR} && \
			cd ${DOCKER_BUILD_DIR} && \
			cmake ${DOCKER_CMAKE_FLAGS} .."
	@echo
	@echo "CMake finished."

.SILENT: build
build: gen-cmake ## Build the cmake project.
	docker run ${DOCKER_BASIC_RUN_PARAMS} \
		${DOCKER_SHELL} -c \
			"cd ${DOCKER_BUILD_DIR} && \
			make -j $$(nproc) ${TARGET}"
	@echo
	@echo "Build finished. The binaries are in ${CURDIR}/${DOCKER_BUILD_DIR}"

.SILENT: clean
clean: ## Clean build files.
	docker run ${DOCKER_BASIC_RUN_PARAMS} \
		${DOCKER_SHELL} -c \
			"rm -rf ${DOCKER_BUILD_DIR}"

.SILENT: run-image
run-image: ## Connect to docker instance with bash
	docker run ${DOCKER_BASIC_RUN_PARAMS} \
		${DOCKER_SHELL}

.SILENT: run-app
run-app: ## Run the application
	docker run ${DOCKER_BASIC_RUN_PARAMS} \
		${DOCKER_SHELL} -c \
			"./${DOCKER_BUILD_DIR}/src/${PROJECT_NAME}"

.SILENT: help
help: ##
	@cat $(MAKEFILE_LIST) | grep -E '^[a-zA-Z_-]+:.*?## .*$$' | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'