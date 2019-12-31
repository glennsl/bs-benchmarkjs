
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
  /** [ description ] A short string describing the host operating system and runtime platform. */
  let description: string = Internal.(getDescription(data));
  /** [ layout ] The host platform's JS interpreter engine. E.g. "WebKit", "V8", "SpiderMonkey". */
  let layout: string = Internal.(getLayout(data));
  /** [ product ] The host device name. E.g. "iPad", "Android Galaxy S3". */
  let product: string = Internal.(getProduct(data));
  /** [ name ] The name of the host platfrom or browser. E.g. "Safari", "Node", "Firefox". */
  let name: string = Internal.(getName(data));
  /** [ manufacturer ] The name of the device manufacturer. E.g. "HP", "Apple", "Microsoft". */
  let manufacturer: string = Internal.(getManufacturer(data));
  /** [ os ] The name of the host operating system. E.g. "Ubuntu 18.04". */
  let os: string = Internal.(getOS(data));
  /** [ prerelease ] */
  let prerelease: string = Internal.(getPrerelease(data));
  /** [ version ] */
  let version: string = Internal.(getVersion(data));
  /** [ toString ] Returns the [ description ] property (string) or an empty string if the description is not available. */
  let toString: unit => string = () => Internal.(toString(data));
};

include (Impl: Intf);
