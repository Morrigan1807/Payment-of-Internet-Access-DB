#pragma once
#include "ChangeLogItem.h"

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для AddPrice
	/// </summary>
	public ref class AddPrice : public System::Windows::Forms::Form
	{
	public:
		AddPrice(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT MAX(ID_price) FROM Prices";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if (dr->HasRows)
			{
				ID_prices->Text = Convert::ToString(Convert::ToInt32(dr[0]) + 1);
			}
			else
			{
				ID_prices->Text = "1";
			}
			dr->Close();
			connect->Close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddPrice()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  ID_prices;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  CPM;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  CPM_20_2;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  CPM_2_6;
	private: System::Windows::Forms::Button^  exit;
	public: Form^ general;

	private: System::Windows::Forms::Button^  Add_row;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddPrice::typeid));
			this->ID_prices = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->CPM = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CPM_20_2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->CPM_2_6 = (gcnew System::Windows::Forms::TextBox());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->Add_row = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// ID_prices
			// 
			this->ID_prices->Location = System::Drawing::Point(27, 38);
			this->ID_prices->Name = L"ID_prices";
			this->ID_prices->ReadOnly = true;
			this->ID_prices->Size = System::Drawing::Size(220, 20);
			this->ID_prices->TabIndex = 0;
			this->toolTip1->SetToolTip(this->ID_prices, L"Это поле заполняется автоматически.");
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(24, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ID цены:";
			this->toolTip1->SetToolTip(this->label1, L"Это поле заполняется автоматически.");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(24, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Дата установки цены:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(27, 87);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(220, 20);
			this->dateTimePicker1->TabIndex = 4;
			this->dateTimePicker1->Value = System::DateTime(2019, 5, 11, 19, 29, 57, 0);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(24, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Стоимость одной минуты:";
			// 
			// CPM
			// 
			this->CPM->Location = System::Drawing::Point(27, 135);
			this->CPM->Name = L"CPM";
			this->CPM->Size = System::Drawing::Size(220, 20);
			this->CPM->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(24, 161);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(223, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Стоимость одной минуты с 20:00 до 02:00:";
			// 
			// CPM_20_2
			// 
			this->CPM_20_2->Location = System::Drawing::Point(27, 177);
			this->CPM_20_2->Name = L"CPM_20_2";
			this->CPM_20_2->Size = System::Drawing::Size(220, 20);
			this->CPM_20_2->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(24, 208);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(223, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Стоимость одной минуты с 02:00 до 06:00:";
			// 
			// CPM_2_6
			// 
			this->CPM_2_6->Location = System::Drawing::Point(27, 224);
			this->CPM_2_6->Name = L"CPM_2_6";
			this->CPM_2_6->Size = System::Drawing::Size(220, 20);
			this->CPM_2_6->TabIndex = 9;
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(197, 271);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 23;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &AddPrice::exit_Click);
			// 
			// Add_row
			// 
			this->Add_row->Location = System::Drawing::Point(12, 271);
			this->Add_row->Name = L"Add_row";
			this->Add_row->Size = System::Drawing::Size(115, 23);
			this->Add_row->TabIndex = 22;
			this->Add_row->Text = L"Добавить строку";
			this->Add_row->UseVisualStyleBackColor = true;
			this->Add_row->Click += gcnew System::EventHandler(this, &AddPrice::Add_row_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(253, 138);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 24;
			this->label6->Text = L"BYN";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Location = System::Drawing::Point(253, 180);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"BYN";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Location = System::Drawing::Point(253, 227);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 13);
			this->label8->TabIndex = 26;
			this->label8->Text = L"BYN";
			// 
			// AddPrice
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 321);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Add_row);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->CPM_2_6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->CPM_20_2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->CPM);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ID_prices);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddPrice";
			this->Text = L"Добавить цены";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddPrice::AddPrice_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Add_row_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (CPM->Text != "" && CPM_20_2->Text != "" && CPM_2_6->Text != "")
		{
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT P_date FROM Prices WHERE P_date = CONVERT(DATE,\'" + this->dateTimePicker1->Text + "\',104)";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if (!(dr->HasRows))
			{
				ChangeLogItem^ ch = gcnew ChangeLogItem("Prices", "INSERT");
				ch->fill_row_update("P_date", "CONVERT(DATE,\'" + this->dateTimePicker1->Text + "\',104)");
				ch->fill_row_update("CPM", "CONVERT(MONEY,'" + this->CPM->Text + "')");
				ch->fill_row_update("CPM_20_2", "CONVERT(MONEY,'" + this->CPM_20_2->Text + "')");
				ch->fill_row_update("CPM_2_6", "CONVERT(MONEY,'" + this->CPM_2_6->Text + "')");
				ch->applyChange();
				MessageBox::Show("Строка успешно добавлена!");
				ID_prices->Text = Convert::ToString(Convert::ToInt32(ID_prices->Text) + 1);
			}
			else
			{
				MessageBox::Show("Ошибка! Строка с данной датой уже существует!");
			}
			dr->Close();
			connect->Close();
		}
		else
		{
			MessageBox::Show("Ошибка ввода!");
		}
	}
private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
{
	general->Enabled = true;
	this->Close();
}
private: System::Void AddPrice_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
};
}
