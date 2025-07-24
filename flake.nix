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
    lib = nixpkgs.lib;
  in {
    devShells.${system}.default = pkgs.mkShell.override {stdenv = pkgs.clangStdenv;} {
      packages = with pkgs; [
        gtest
        cmake
      ];

      CPATH = builtins.concatStringsSep ":" [
        (lib.makeSearchPathOutput "dev" "include" [pkgs.gtest])
        (lib.makeSearchPath "resource-root/include" [pkgs.clang])
      ];
    };
    formatter.${system} = pkgs.alejandra;
  };
}
