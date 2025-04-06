{
  description = "Learning DSA with LeetCode: A structured roadmap for mastering Data Structures and Algorithms";
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
      ];
      CXX = "${pkgs.clang}/bin/clang++";
    };
    formatter.${system} = pkgs.alejandra;
  };
}
