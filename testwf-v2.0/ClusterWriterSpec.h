// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// @file   ClusterWriterSpec.h

#ifndef O2_MFT_CLUSTERWRITER_H_
#define O2_MFT_CLUSTERWRITER_H_

#include "TFile.h"

#include "Framework/DataProcessorSpec.h"
#include "Framework/Task.h"

using namespace o2::framework;

namespace o2
{
namespace MFT
{

class ClusterWriter : public Task
{
 public:
  ClusterWriter() = default;
  ~ClusterWriter() = default;
  void init(InitContext& ic) final;
  void run(ProcessingContext& pc) final;

 private:
  int mState = 0;
  std::unique_ptr<TFile> mFile = nullptr;
};

/// create a processor spec and write MFT clusters in a root file
framework::DataProcessorSpec getClusterWriterSpec();

} // namespace MFT
} // namespace o2

#endif /* O2_MFT_CLUSTERWRITER_H */
