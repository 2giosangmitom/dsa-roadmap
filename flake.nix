{
  description = "LeetCode solutions implemented in JS";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    systems = ["x86_64-linux" "aarch64-linux"];

    forAllSystems = f:
      nixpkgs.lib.genAttrs systems (system: let
        pkgs = import nixpkgs {inherit system;};
      in
        f pkgs system);
  in {
    devShells = forAllSystems (pkgs: system: {
      default = pkgs.mkShellNoCC {
        buildInputs = with pkgs; [
          nodejs_23
          pnpm
        ];
      };
    });
    formatter = forAllSystems (pkgs: system: pkgs.alejandra);
  };
}
