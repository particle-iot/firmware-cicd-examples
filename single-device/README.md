# Single Device

This example demonstrates how to use GitHub Actions to compile firmware and flash to a single device.

## Getting Started

1. Create a new file called `.github/workflows/build.yaml` in your Particle project repository.
1. Add the following content to the `build.yaml` file:

    ```yaml
    name: Compile and Flash

    on: [push]

    jobs:
      build:
        runs-on: ubuntu-latest
        steps:
          - name: Checkout code
            uses: actions/checkout@v3

          - name: Compile application
            id: compile
            uses: particle-iot/compile-action@v1
            with:
              particle-access-token: ${{ secrets.PARTICLE_ACCESS_TOKEN }}
              particle-platform-name: '<your-platform-name>'

          - name: Flash development device on main branch
            if: github.ref == 'refs/heads/main'
            uses: particle-iot/flash-device-action@v1
            with:
              particle-access-token: ${{ secrets.PARTICLE_ACCESS_TOKEN }}
              firmware-path: ${{ steps.compile.outputs.firmware-path }}
              device-id: '<your-device-id>'

          - name: Upload artifact
            uses: actions/upload-artifact@v3
            with:
              name: firmware
              path: ${{ steps.compile.outputs.firmware-path }}
    ```

1. Replace `<your-platform-name>` and `<your-device-id>` with the name of your target Particle platform (e.g., 'boron') and your device ID, respectively. See [docs](https://github.com/particle-iot/compile-action#usage) for a list of platform names.
1. Set the `PARTICLE_ACCESS_TOKEN` secret in your repository settings. See [Particle docs](https://docs.particle.io/firmware/best-practices/github-actions/#obtain-an-access-token) and [GitHub docs](https://docs.github.com/en/actions/reference/encrypted-secrets#creating-encrypted-secrets-for-a-repository) for more information.
1. Commit and push the `compile.yml` file to your repository.
1. The GitHub Actions workflow will automatically start compiling your firmware upon each push to the repository. You can view the status of the workflow in the "Actions" tab of your repository.
1. When the push even occurs on the `main` branch, the compiled firmware will be flashed to the device specified.
1. Once the compile job is completed, the compiled binary will be uploaded as an artifact in the GitHub Actions run. You can download it from the "Artifacts" section of the completed workflow run.
