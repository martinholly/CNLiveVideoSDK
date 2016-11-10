Pod::Spec.new do |s|

  s.name          = 'CNLiveVideoSDK'
  s.version       = '0.8'
  s.summary       = 'CNLiveVideo iOS SDK'
  s.homepage      = 'http://open.cnlive.com'
  s.platform      = :ios, '7.0'
  s.source        = {
      :git => 'https://github.com/qpwang/CNLiveVideoSDK.git',
      :tag => 'V0.8'
  }
  s.source_files = 'SDK/*.h'
  s.vendored_frameworks = 'SDK/CNLiveUGC.framework'
  s.resources = 'SDK/*.bundle'
  s.license = 'MIT'
  s.requires_arc = false
  s.authors = 'martin'
end

