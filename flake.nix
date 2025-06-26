{
  description = "Learn DSA with LeetCode";
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
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        gtest
        cmake
        clang
        ninja
        python3Minimal
      ];
    };
    formatter.${system} = pkgs.alejandra;
  };
}
