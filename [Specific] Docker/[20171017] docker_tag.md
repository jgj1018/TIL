[reference1](https://docs.docker.com/engine/reference/commandline/tag/#examples)

# tagging

docker image tag

assign one or more tags to an image.
Image don't technically have a name.
Tagging images for uplad to Docker Hub

: tag is not quite a version and it's not quite a branch. it is a pointer to a specific image commit and reall could be anything into that repository. It will not change image_id.

To tag a local image with ID "10a" into "AAA" repository with "version1.0"

```
docker tag 10a AAA/httpd:version1.0
```

the place for image_id can be replaced with name(httpd). if tag name is not specified, the alias is created for an existing local version httpd:latest.

basic format is below

```
<user>/<repo>:<tag>
```

repo is actauuly made up of name of user or organization.
repo name includes the organization name

```
REPOSITORY TAG IMAGE_ID
nginx latest db0~
nginx mainline db0~
```
these tags are just labels that point to a actual image ID and I can have many of them all point to the same one.
