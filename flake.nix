{
  description = "Learning DSA with LeetCode";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};
  in {
    devShells.${system}.default = pkgs.mkShellNoCC {
      packages = with pkgs; [
        gtest
        cmake
        clang
        ninja
      ];
    };
    formatter.${system} = pkgs.alejandra;
  };
}
