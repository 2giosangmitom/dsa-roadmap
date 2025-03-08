let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-unstable";
  pkgs = import nixpkgs {};
in
  pkgs.mkShellNoCC {
    packages = with pkgs; [
      nodejs_23
      gtest
      cmake
    ];
  }
