
module type Intf = {
  let description: string;
  let layout: string;
  let product: string;
  let name: string;
  let manufacturer: string;
  let os: string;
  let prerelease: string;
  let version: string;
  let toString: unit => string;
};

module Impl = {
  module Internal = BenchmarkJs__FFI.Platform;
  /** [description] A short string describing the host operating system and runtime platform. */
  let description: string = Internal.(getDescription(data));
  /** [layout] The host platform's JS interpreter engine. */
  let layout: string = Internal.(getLayout(data));
  let product: string = Internal.(getProduct(data));
  let name: string = Internal.(getName(data));
  let manufacturer: string = Internal.(getManufacturer(data));
  let os: string = Internal.(getOS(data));
  let prerelease: string = Internal.(getPrerelease(data));
  let version: string = Internal.(getVersion(data));
  let toString: unit => string = () => Internal.(toString(data));
};

include (Impl: Intf);
