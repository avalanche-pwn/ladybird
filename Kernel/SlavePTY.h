#pragma once

#include "TTY.h"

class MasterPTY;

class SlavePTY final : public TTY {
    AK_MAKE_ETERNAL
public:
    virtual ~SlavePTY() override;

    virtual String tty_name() const override;

    void on_master_write(const byte*, size_t);

protected:
    virtual void on_tty_write(const byte*, size_t) override;
    virtual bool can_write(Process&) const override;

private:
    friend class MasterPTY;
    SlavePTY(MasterPTY&, unsigned index);

    MasterPTY& m_master;
    unsigned m_index;
};

