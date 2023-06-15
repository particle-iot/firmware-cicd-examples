# product-firmware

A product firmware project with two GitHub Action pipelines:

 * [`build`](../.github/workflows/product-firmware-build.yaml):
   1. compiles application firmware on every git push:
   2. on pushes to the `main` branch, it will also flash to a development device (for example, after merging a pull request)
 * [`release`](../.github/workflows/product-firmware-release.yaml):
   1. increments `PRODUCT_VERSION` macro if needed (via the [`auto-version`](https://github.com/particle-iot/compile-action/blob/feature/auto-version/AUTO_VERSION.md) feature of `compile-action`)
   2. compiles application firmware
   3. creates a GitHub release
   4. uploads firmware to the Particle product
   5. flashes the firmware release to a development device

This demo uses the Cloud Compiler and therefore does not capture some artifacts like the ELF, MAP, and HEX files.
To access those artifacts via the `target-path` output, remove the `particle-access-token` parameter on `compile-action` to compile locally.
Refer to the [example pipeline](https://github.com/particle-iot/compile-action#example-pipeline) for more information. 
